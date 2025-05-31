# Viking DGD Release Process

This document describes the process for updating the Viking DGD fork with the latest changes from the official DGD repository.

## Overview

Viking DGD is a fork of the official DGD driver with custom patches. This process ensures we can pull in upstream changes while maintaining our modifications.

## Prerequisites

- Git installed with SSH access to GitHub
- Write access to the Viking DGD repository
- Basic understanding of git rebase and conflict resolution

## Process Steps

### 1. Clone the Viking DGD Repository

Clone the Viking fork using SSH (required for pushing changes):

```bash
git clone git@github.com:VikingMud/viking-dgd.git
cd viking-dgd
```

### 2. Add Official DGD as Upstream Remote

Add the official DGD repository as an upstream remote:

```bash
git remote add upstream https://github.com/dworkin/dgd.git
```

Verify the remotes are configured correctly:

```bash
git remote -v
# Should show:
# origin    git@github.com:VikingMud/viking-dgd.git (fetch)
# origin    git@github.com:VikingMud/viking-dgd.git (push)
# upstream  https://github.com/dworkin/dgd.git (fetch)
# upstream  https://github.com/dworkin/dgd.git (push)
```

### 3. Fetch Latest Upstream Changes

Fetch all branches and tags from upstream:

```bash
git fetch upstream --tags
```

### 4. Determine Version Source

Check if you're pulling from a tagged release or master:

```bash
# List recent tags
git tag --sort=-version:refname | head -10

# Check latest commits on upstream master
git log --oneline -n 10 upstream/master
```

**Important**: Note whether you're updating to a specific tagged release or pulling unreleased changes from master.

### 5. Create Release Branch

Create a new branch following the Viking naming convention:

- For tagged releases: `viking-X.Y.Z-YYYYMMDD`
- For master (unreleased): Use the last tagged version as the base version

```bash
# Example: Updating to tag 1.7.6
git checkout -b viking-1.7.6-$(date +%Y%m%d)

# Example: Updating from master (when last tag was 1.7.6)
git checkout -b viking-1.7.6-$(date +%Y%m%d)
```

### 6. Rebase onto Upstream

**Important**: Use rebase instead of merge to maintain a cleaner history.

```bash
# For rebasing onto a specific tag
git rebase 1.7.6

# For rebasing onto master
git rebase upstream/master
```

### 7. Resolve Conflicts

During the rebase, you may encounter conflicts. Common conflict areas include:

- `src/config.h` - Configuration definitions
- `src/Makefile` - Build settings
- Files containing Viking-specific patches

When resolving conflicts:
1. Carefully review what upstream changed
2. Preserve Viking-specific modifications where needed
3. Accept upstream changes that don't conflict with Viking functionality

```bash
# After resolving conflicts in a file
git add <resolved-file>
git rebase --continue

# If you need to abort and start over
git rebase --abort
```

### 8. Test the Build

After successful rebase, ensure the code compiles:

```bash
cd src
make clean
make
```

### 9. Update Master Branch

Once testing is complete, fast-forward master to the rebased branch:

```bash
git checkout master
git reset --hard viking-1.7.6-YYYYMMDD
```

**Note**: This replaces master's history with the rebased branch. This is the recommended approach for maintaining a fork as it keeps history clean and makes Viking-specific changes easy to identify.

### 10. Create Release Tag

Tag the release with the same name as the branch:

```bash
git tag -a viking-1.7.6-$(date +%Y%m%d) -m "Viking DGD updated to upstream 1.7.6"

# Or if updating from master
git tag -a viking-1.7.6-$(date +%Y%m%d) -m "Viking DGD updated from upstream master"
```

### 11. Push Changes

Since we rebased, we need to force push to update the remote repository:

```bash
git push --force-with-lease origin master
```

**Important**: The `--force-with-lease` option is safer than `--force` as it will fail if someone else has pushed to the branch since you last fetched. This is necessary because rebasing rewrites history.

Then push the new tag:

```bash
git push origin refs/tags/viking-1.7.6-YYYYMMDD
```

## Notes on Viking Patches

The Viking fork includes several custom modifications that must be preserved during updates:

- VIKING and SLASHSLASH defines in Makefile
- LARGENUM support for larger numeric types
- Custom kernel functions (`add_viking_kernel_functions`)
- Additional configuration options

Always verify these patches are intact after rebasing.

## Troubleshooting

### Rebase Conflicts

If you encounter difficult conflicts during rebase:

1. Use `git status` to see which files have conflicts
2. Use `git diff` to understand the nature of the conflicts
3. Look at the commit history with `git log --oneline --graph` to understand the changes
4. Consider using `git rebase -i` for more control over the process