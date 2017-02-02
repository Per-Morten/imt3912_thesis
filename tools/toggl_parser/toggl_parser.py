#based on: http://stackoverflow.com/questions/12296585/python-parse-csv-correctly

import csv 
import sys
import re

def time_to_minutes(hours, minutes):
    total_time = hours * 60
    total_time += minutes
    return total_time

def is_csv_file(filename):
    match = re.match(r'.*\.csv', filename)
    return match != None

def create_csv_dictionary(csv_file_name):
    category = {}
    category['User'] = []
    category['Email'] = []
    category['Client'] = []
    category['Project'] = []
    category['Task'] = []
    category['Description'] = []
    category['Billable'] = []
    category['Start date'] = []
    category['Start time'] = []
    category['End date'] = []
    category['End time'] = []
    category['Duration'] = []
    category['Tags'] = []
    category['Amount ()'] = []
    
    dictionary_reader = csv.DictReader(open(csv_file_name, 'rt'), fieldnames = ['User','Email','Client','Project','Task','Description','Billable','Start date','Start time','End date','End time','Duration','Tags','Amount ()'], delimiter = ',')
    
    for row in dictionary_reader:
        for key in row:
            category[key].append(row[key])

    return category

def main():
    if len(sys.argv) < 1 or (not is_csv_file(sys.argv[1])):
        print("Usage: toggle_parser.py <toggle_file>.csv")
        return

    toggl_info = create_csv_dictionary(sys.argv[1])

    issue_time = {}

    index = 1
    while index < len(toggl_info['User']):
        issue = re.search(r'Issue #([0-9].)', toggl_info['Description'][index])
        if issue:
            id = issue.group(1)
            if id not in issue_time.keys():
                issue_time[id] = 0

            time_text = re.search(r'([0-9].):([0-9].):([0-9].)', toggl_info['Duration'][index])
            issue_time[id] += time_to_minutes(int(time_text.group(1)), int(time_text.group(2)))
        
        index += 1

    print("id,time_in_minutes")

    for key, value in sorted(issue_time.items()):
        if value != 0:
            print("%4d,%6d" % (int(key), value))           

if __name__ == "__main__":
    main()