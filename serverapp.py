from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

def run_cpp_executable(command):
    try:
        # Update the path to your executable if necessary
        result = subprocess.run(['./test.exe'] + command, capture_output=True, text=True, timeout=30)
        return result.stdout
    except subprocess.TimeoutExpired:
        return "The C++ executable took too long to respond."
    except Exception as e:
        return str(e)

@app.route('/add_student', methods=['POST'])
def add_student():
    data = request.json
    command = ['1', data['rollNo'], data['name'], data['subject'], data['address']]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/search_student', methods=['GET'])
def search_student():
    rollNo = request.args.get('rollNo')
    command = ['2', rollNo]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/update_student', methods=['PUT'])
def update_student():
    data = request.json
    command = ['3', data['rollNo'], data['name'], data['subject'], data['address']]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/delete_student', methods=['DELETE'])
def delete_student():
    rollNo = request.args.get('rollNo')
    command = ['4', rollNo]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/show_all_students', methods=['GET'])
def show_all_students():
    command = ['5']
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/add_teacher', methods=['POST'])
def add_teacher():
    data = request.json
    command = ['6', data['name'], data['qualification'], data['phoneNumber'], data['address']]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/update_teacher', methods=['PUT'])
def update_teacher():
    data = request.json
    command = ['7', data['name'], data['qualification'], data['phoneNumber'], data['address']]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/delete_teacher', methods=['DELETE'])
def delete_teacher():
    name = request.args.get('name')
    command = ['8', name]
    output = run_cpp_executable(command)
    return jsonify({'result': output})

@app.route('/show_all_teachers', methods=['GET'])
def show_all_teachers():
    command = ['9']
    output = run_cpp_executable(command)
    return jsonify({'result': output})

if __name__ == '__main__':
    app.run(debug=True)
