#### PT Commit Standard  
##### Rationale  
Git Repos can quickly become quite messy when used regularly.
To keep the repo manageable, as well as tracking progress and work, a standard is put in place.  

##### Standard
<issue_action> #(issue number): heading
(empty line)
explanatory body

<footer>
<time_logging> $time #(issue number) <hours>h <minutes>m

###### Example:
ref #6: create standard

Creating standard for commit messages.  

ref #7 #8
$time #6 1h 30m

##### Time Clarification
Logging time does not need to happen in each commit,
however it should happen when a large portion of work has been done,
or the issue is closed.

##### Issue actions
Legal issue actions are:
ref  
fix

Other actions are done through the bitbucket issue tracker.

##### Heading
The heading will be written in an imperative form.  
i.e. fix instead of fixed.  
This only applies to headings.  
Keep headings short, around 50 characters.  
Capitalize headings.  

##### Resources
Inspiration were taken from:  
http://chris.beams.io/posts/git-commit/  
Further reading regarding good commit practices can be found there.