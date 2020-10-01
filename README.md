## Welcome to Algorithm and Data Structure :clipboard:

Our open source focused on providing solutions to the complex programming problems. 


## Steps to follow :scroll:

### 1. Fork it :fork_and_knife:

You can get your own fork/copy of [Algo&Ds](https://github.com/sansyrox/algorithm-ds) by using the <a href="https://github.com/sansyrox/algorithm-ds/new/master?readme=1#fork-destination-box"><kbd><b>Fork</b></kbd></a> button or clicking [this](https://github.com/sansyrox/algorithm-ds/new/master?readme=1#fork-destination-box).

 [![Fork Button](https://help.github.com/assets/images/help/repository/fork_button.jpg)](https:/github.com/sansyrox/algorithm-ds)

### 2. Clone it :busts_in_silhouette:

You can clone (download) it to computer using

```sh
$ git clone https://github.com/sansyrox/algorithm-ds.git
```

> This makes a local copy of repository on your computer.

Once you have cloned the `Algo&DS` repository in Github, move to that folder first using change directory command on linux and Mac.

```sh
# This will change directory to a folder Algo&DS
$ cd Algo&Ds
```

Move to this folder for all other commands.

### 3. Set it up :arrow_up:

Run the following commands to see that *your local copy* has a reference to *your forked remote repository* in Github :octocat:

```sh
$ git remote -v
origin  https://github.com/sansyrox/algorithm-ds.git (fetch)
origin  https://github.com/sansyrox/algorithm-ds.git(push)
```

Now, lets add a reference to the original [Algo&Ds](https://github.com/sansyrox/algorithm-ds) repository using

```sh
$ git remote add upstream https://github.com/sansyrox/algorithm-ds.git
```

> This adds a new remote named ***upstream***.

See the changes using

```sh
$ git remote -v
origin    https://github.com/sansyrox/algorithm-ds.git (fetch)
origin    https://github.com/sansyrox/algorithm-ds.git (push)
upstream  https://github.com/sansyrox/algorithm-ds.git (fetch)
upstream  https://github.com/sansyrox/algorithm-ds.git (push)
```

### 4. Sync it :recycle:

Always keep your local copy of repository updated with the original repository.
Before making any changes and/or in an appropriate interval, run the following commands *carefully* to update your local repository.

```sh
# Fetch all remote repositories and delete any deleted remote branches
$ git fetch --all --prune

# Switch to `master` branch
$ git checkout master

# Reset local `master` branch to match `upstream` repository's `master` branch
$ git reset --hard upstream/master

# Push changes to your forked `Algo&Ds` repo
$ git push origin master
```

### 5. Create a new branch :bangbang:

Whenever you are going to make contribution. Please create separate branch using command and keep your `master` branch clean (i.e. synced with remote branch).

```sh
# It will create a new branch with name Branch_Name and switch to branch Folder_Name
$ git checkout -b Folder_Name
```

Create a seperate branch for contibution and try to use same name of branch as of folder.

To switch to desired branch

```sh
# To switch from one folder to other
$ git checkout Folder_Name
```

To add the changes to the branch. Use

```sh
# To add all files to branch Folder_Name
$ git add .
```

Type in a message relevant for the code reveiwer using

```sh
# This message get associated with all files you have changed
$ git commit -m 'relevant message'
```

Now, Push your awesome work to your remote repository using

```sh
# To push your work to your remote repository
$ git push -u origin Folder_Name
```

Finally, go to your repository in browser and click on `compare and pull requests`.
Then add a title and description to your pull request that explains your precious effort.

