import json
import os

registered_courses_str = 'registered_courses'
student_name_str = 'student_name'
course_name_str = 'course_name'
lecturers_str = 'lecturers'
json_extension = '.json'
quotes = '"'
space = ' '
end_line = '\n'
one_tab = 4
read = 'r'
write = 'w'


def names_of_registered_students(input_json_path, course_name):
    """
    This function returns a list of the names of the students who registered for
    the course with the name "course_name".

    :param: input_json_path: Path of the students' database json file.
    :param: course_name: The name of the course.
    :return: List of the names of the students.
    """
    output = []
    with open(input_json_path, read) as json_file:
        data = json.load(json_file)
    for v in data.values():
        if course_name in v[registered_courses_str]:
            output.append(v[student_name_str])
    return output


def enrollment_numbers(input_json_path, output_file_path):
    """
    This function writes all the course names and the number of enrolled
    student in ascending order to the output file in the given path.

    :param: input_json_path: Path of the students' database json file.
    :param: output_file_path: Path of the output text file.
    """
    courses_dict = {}
    with open(input_json_path, read) as json_file:
        data = json.load(json_file)
    for v in data.values():
        for courses in v[registered_courses_str]:
            if courses in courses_dict:
                courses_dict[courses] = courses_dict.get(courses)+1
            else:
                courses_dict[courses] = 1
    with open(output_file_path, write) as f:
        for key, value in sorted(courses_dict.items()):
            curr_str = quotes + key + quotes + space + "{}".format(value) + end_line
            f.write(curr_str)


def courses_for_lecturers(json_directory_path, output_json_path):
    """
    This function writes the courses given by each lecturer in json format.

    :param: json_directory_path: Path of the semesters_data files.
    :param: output_json_path: Path of the output json file.
    """
    json_files = [file for file in os.listdir(json_directory_path) if file.endswith(json_extension)]
    res = {}
    for file in json_files:
        file_path = os.path.join(json_directory_path, file)
        with open(file_path, read) as curr_file:
            loaded_file = json.load(curr_file)
        for course_id in loaded_file:
            course_name = loaded_file[course_id][course_name_str]
            lecturers_list = loaded_file[course_id][lecturers_str]
            for lecturer in lecturers_list:
                if lecturer in res:
                    if course_name not in res[lecturer]:  # has not taught it yet
                        res[lecturer].append(course_name)
                else:
                    res[lecturer] = [course_name]  # add lecturer and course_name
    with open(output_json_path, write) as final_file:
        json.dump(res, final_file, indent=one_tab)
