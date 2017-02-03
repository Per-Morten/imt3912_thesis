import csv
import sys
import re

#Hillariously ugly. But atleast it functions.

class time_info(object):
    pass

class time_in_dhm_format(object):
    pass

def time_to_dhm_format(time_in_minutes):
    time = time_in_dhm_format()
    time.hours = time_in_minutes / 60
    time.minutes = time_in_minutes % 60
    time.days = time.hours / 8
    time.hours = time.hours % 8 
    return time

def is_csv_file(filename):
    match = re.match(r'.*\.csv', filename)
    return match != None

def create_csv_dictionary(csv_file_name):
    container = {}
    container['id'] = []
    container['time_in_minutes'] = []

    with open(csv_file_name, 'rt') as csv_file:
        next(csv_file)
        dictionary_reader = csv.DictReader(csv_file, fieldnames = ['id','time_in_minutes'], delimiter = ',')
        
        for row in dictionary_reader:
            for key in row:
                container[key].append(row[key])

    dictionary = {}

    index = 0
    while index < len(container['id']):
        dictionary[container['id'][index]] = container['time_in_minutes'][index]
        index += 1

    return dictionary

def main():
    if len(sys.argv) < 2 or not is_csv_file(sys.argv[1]) or not is_csv_file(sys.argv[2]):
        print("Usage: estimation_preciseness.py <estimation_file>.csv <time_log_file>.csv")
        return

    estimates = create_csv_dictionary(sys.argv[1])
    time_logged = create_csv_dictionary(sys.argv[2])

    delta = {}

    for key, value in estimates.items():
        if key in time_logged:
            delta[key] = time_info()
            delta[key].id = int(key)
            delta[key].estimate = int(value)
            delta[key].time_logged = int(time_logged[key])
            delta[key].time_remaining = delta[key].estimate - delta[key].time_logged

    text_format = "Id: %3d Estimate: %2dd %2dh %2dm Logged: %2dd %2dh %2dm Remaining Time: % 2dd %2dh %2dm"

    for key, value in sorted(delta.items()):
        estimate = time_to_dhm_format(value.estimate)
        time_logged = time_to_dhm_format(value.time_logged)
        time_remaining = time_to_dhm_format(value.time_remaining)
        print(text_format % (int(key), estimate.days, estimate.hours, estimate.minutes, 
                                       time_logged.days, time_logged.hours, time_logged.minutes, 
                                       time_remaining.days, time_remaining.hours, time_remaining.minutes))

if __name__ == "__main__":
    main()