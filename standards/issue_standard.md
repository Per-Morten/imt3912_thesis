### PT Issue Standard
#### Rationale  
Keeping track of issues is an important and sometimes daunting task,
to make this task easer we have therefore decided to add an own standard
for writing issues.

#### Standard
##### Title  
Keep the heading short and to the point.  
Prefer to write in imperative form.  
Capitalize heading.  

##### Body  
###### Issue description  
Issue description should give as much explanation as needed of the situation.  
This is again based on what sort of issue it is.  

###### Bug  
Give as much explanation as possible regarding when the bug occurs, if possible give a minimum example to reproduce.  
Time estimate is optional.  

###### Task  
Give a proper outline of what sort of work that needs to be done.  
Level of detail is up to the reporter, however try to keep it as detailed as possible.  
Give a time estimate on how long time it will take to complete the task.  
A task can consist of a couple of steps, however if those steps are of a larger degree, consider creating more tasks and refer to the "parent" task.  

###### Enhancement  
Explain what enhancement that needs to be done where.  
Give also a rationale for why.  
Give a time estimate on how long time it will take to complete the task.  

###### All Issues  
All issues that somehow are linked with other issues will refer to them at the footer.  
If there are special reasons for referring to other issues, those will be written next to the issue.  

##### Priority
All priority levels will be used.  
Their importance should be self explanatory, the exception is blocker, which has some special semantics.  
Blockers will only be used in cases where it is detrimental for another group members work-flow.  
Blocker should then only appear as a priority in exceptional situations, a type of "drop everything you got and fix this" setting.  
Because of this blockers do not require time estimations, and can ignore the issue standard.

##### Estimate
Estimates are required on tasks and enhancements, but are optional on bugs.  
Estimates are written at the bottom of the issue body in the following format:  
$estimate <days>d <hours>h <minutes>m  
In this case days are 8 hours.

##### Changes
Prefer to keep all changes within the issue description itself,  
i.e. better to update than to comment on the issue.  
When updating an issue give a comment related to what you changed, and potentially why.  
