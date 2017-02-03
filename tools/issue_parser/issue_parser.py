import json
import re
import sys

def is_json_file(filename):
    match = re.match(r'.*\.json', filename)
    return match != None

def main():
    if len(sys.argv) < 1 or (not is_json_file(sys.argv[1])):
        print("Usage: issue_parser.py <issue_file>.json")
        return

    with open(sys.argv[1]) as data_file:   
        data = json.load(data_file)
    
        pattern = r'\$estimate\s([0-9]+d)?(\s)?([0-9]+h)?(\s)?([0-9]+m)?'
    
        print("id,time_in_minutes")
    
        for issue in data["issues"]:
            description = issue["content"]
            estimate_text = re.search(pattern, description)
    
            output_format = "%4d,%6d"
    
            if estimate_text:
                estimate = ""
                days = re.search(r'([0-9])+d', estimate_text.group(0))
                hours = re.search(r'([0-9])+h', estimate_text.group(0))
                minutes = re.search(r'([0-9])+m', estimate_text.group(0))
    
                estimate_in_minutes = 0
                if days:
                    estimate += days.group(1) + " "
                    estimate_in_minutes += int(days.group(1)) * 8 * 60
                if hours:
                    estimate += hours.group(1) + " "
                    estimate_in_minutes += int(hours.group(1)) * 60
                if minutes:
                    estimate += minutes.group(1) + " "
                    estimate_in_minutes += int(minutes.group(1))
    
                print(output_format % (issue["id"], estimate_in_minutes))        
    
if __name__ == "__main__":
    main()