# Git Cheat Sheet

## Basic Commands

| Command               | Description               |
|-----------------------|---------------------------|
| `git init`            | Initialize a new git repo |
| `git clone <url>`     | Clone a remote repo       |
| `git status`          | Show modified files       |
| `git add <file>`      | Stage file(s) for commit  |
| `git commit -m "msg"` | Commit with message       |
| `git commit --amend`  | Modify last commit        |
| `git log`             | View commit history       |
| `git diff`            | Show file differences     |
| `git rm <file>`       | Remove file from repo     |
| `git mv <old> <new>`  | Rename or move a file     |

---

## Branching

| Command                    | Description                                   |
|----------------------------|-----------------------------------------------|
| `git branch`               | List branches                                 |
| `git branch <name>`        | Create new branch                             |
| `git checkout <name>`      | Switch to branch                              |
| `git checkout -b <name>`   | Create and switch to new branch               |
| `git switch <name>`        | (Alt) Switch to branch                        |
| `git switch -c <name>`     | Create and switch to new branch               |
| `git merge <branch>`       | Merge into current branch                     |
| `git branch -d <name>`     | Delete branch                                 |
| `git branch -D <name>`     | Force delete branch                           |
| `git cherry-pick <commit>` | Apply a specific commit to the current branch |

---

## Remote

| Command                             | Description                       |
|-------------------------------------|-----------------------------------|
| `git remote -v`                     | Show remote URLs                  |
| `git remote add origin <url>`       | Add remote                        |
| `git push -u origin <branch>`       | Push to remote                    |
| `git pull`                          | Pull latest changes               |
| `git pull --rebase`                 | Pull with rebase instead of merge |
| `git fetch`                         | Fetch from remote                 |
| `git push`                          | Push commits                      |
| `git remote remove <name>`          | Remove a remote                   |
| `git push origin --delete <branch>` | Delete remote branch              |

---

## Undoing Things

| Command                       | Description                     |
|-------------------------------|---------------------------------|
| `git restore <file>`          | Undo changes (not staged)       |
| `git restore --staged <file>` | Unstage a file                  |
| `git reset --hard HEAD~1`     | Reset commit and changes        |
| `git revert <commit>`         | Revert a commit                 |
| `git reset <file>`            | Unstage a file (keep changes)   |
| `git clean -f`                | Remove untracked files          |
| `git clean -fd`               | Remove untracked files and dirs |

---

## Tags & Releases

| Command                          | Description        |
|----------------------------------|--------------------|
| `git tag`                        | Show tags          |
| `git tag v1.0`                   | Create tag         |
| `git tag -a v1.0 -m "msg"`       | Annotated tag      |
| `git push origin v1.0`           | Push tag to remote |
| `git tag -d <tag>`               | Delete a local tag |
| `git push origin --delete <tag>` | Delete remote tag  |

---

## History & Visualization

| Command                              | Description                             |
|--------------------------------------|-----------------------------------------|
| `git log --oneline`                  | Compact log format                      |
| `git log --graph --all`              | Visualize all branches                  |
| `git log --stat`                     | Log with file change stats              |
| `git show <commit>`                  | Show details of a specific commit       |

---

## Git Rebase & Bisect

| Command                    | Description                        |
|----------------------------|------------------------------------|
| `git rebase <branch>`      | Reapply commits on top of a branch |
| `git rebase -i <commit>`   | Interactive rebase (edit history)  |
| `git rebase --abort`       | Abort a rebase                     |
| `git rebase --continue`    | Continue after resolving conflicts |
| `git bisect start`         | Start binary search for a bug      |
| `git bisect good <commit>` | Mark a commit as good              |
| `git bisect bad <commit>`  | Mark a commit as bad               |
| `git bisect reset`         | End the bisect session             |
| `git bisect log`           | Show steps taken during bisect     |
| `git bisect run <cmd>`     | Run a command to automate bisect   |
| `git bisect skip`          | Skip a commit                      |

## Stash

| Command                   | Description                             |
|---------------------------|-----------------------------------------|
| `git stash`               | Save local changes temporarily          |
| `git stash list`          | View list of stashes                    |
| `git stash pop`           | Reapply last stash and remove it        |
| `git stash apply`         | Reapply last stash without deleting it  |
| `git stash drop`          | Delete the most recent stash            |
| `git stash clear`         | Remove all stashes                      |
| `git stash show`          | Show changes in the last stash          |
| `git stash show -p`       | Show detailed changes in the last stash |
| `git stash branch <name>` | Create a new branch from a stash        |
| `git stash apply <stash>` | Apply a specific stash                  |

_Use git stash to temporarily save changes that aren’t yet ready to be committed — useful when switching branches or testing something else._

---

## Git Config

| Command                                       | Description             |
|-----------------------------------------------|-------------------------|
| `git config --global user.name "Your Name"`   | Set name                |
| `git config --global user.email "email"`      | Set email               |
| `git config --global core.editor vim`         | Set editor              |
| `git config --global init.defaultBranch main` | Set default branch name |
| `git config --list`                           | List all config values  |

---

## Aliases

| Command                                 | Description               |
|-----------------------------------------|---------------------------|
| `git config --global alias.co checkout` | `git co` = `git checkout` |
| `git config --global alias.br branch`   | `git br` = `git branch`   |
| `git config --global alias.st status`   | `git st` = `git status`   |
| `git config --global alias.cm commit`   | `git cm` = `git commit`   |

---

## Git Flow (Standard)

```sh
main                # stable production code
│
├─ develop          # main development branch
│   ├─ feature/xyz  # new feature being built
│   └─ feature/abc
│
├─ release/x.x      # preparing a version for release
│
└─ hotfix/x.x.x     # quick emergency fix
```

---

## Utils

- Use `.gitignore` to skip unnecessary files.
- Use `git stash` to save uncommitted changes.
- Use `git log --oneline --graph --all` to visualize branches.
- Use `git archive` to create a tarball of the repository.
- Use `git blame <file>` to see who changed each line of a file.
- Use `git shortlog` to summarize commit history by author.

---

_This cheat sheet is a quick reference guide for common Git commands and workflows. It is not exhaustive but covers the most frequently used commands._