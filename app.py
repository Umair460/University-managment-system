import streamlit as st
import requests

API_URL = 'http://localhost:5000'

def add_student():
    rollNo = st.text_input('Roll No')
    name = st.text_input('Name')
    subject = st.text_input('Subject')
    address = st.text_input('Address')

    if st.button('Add Student'):
        response = requests.post(f'{API_URL}/add_student', json={
            'rollNo': rollNo,
            'name': name,
            'subject': subject,
            'address': address
        })
        st.write(response.json())

def search_student():
    rollNo = st.text_input('Roll No')

    if st.button('Search Student'):
        response = requests.get(f'{API_URL}/search_student', params={'rollNo': rollNo})
        st.write(response.json())

def update_student():
    rollNo = st.text_input('Roll No')
    name = st.text_input('Name')
    subject = st.text_input('Subject')
    address = st.text_input('Address')

    if st.button('Update Student'):
        response = requests.put(f'{API_URL}/update_student', json={
            'rollNo': rollNo,
            'name': name,
            'subject': subject,
            'address': address
        })
        st.write(response.json())

def delete_student():
    rollNo = st.text_input('Roll No')

    if st.button('Delete Student'):
        response = requests.delete(f'{API_URL}/delete_student', params={'rollNo': rollNo})
        st.write(response.json())

def show_all_students():
    if st.button('Show All Students'):
        response = requests.get(f'{API_URL}/show_all_students')
        st.write(response.json())

def add_teacher():
    name = st.text_input('Name')
    qualification = st.text_input('Qualification')
    phoneNumber = st.text_input('Phone Number')
    address = st.text_input('Address')

    if st.button('Add Teacher'):
        response = requests.post(f'{API_URL}/add_teacher', json={
            'name': name,
            'qualification': qualification,
            'phoneNumber': phoneNumber,
            'address': address
        })
        st.write(response.json())

def update_teacher():
    name = st.text_input('Name')
    qualification = st.text_input('Qualification')
    phoneNumber = st.text_input('Phone Number')
    address = st.text_input('Address')

    if st.button('Update Teacher'):
        response = requests.put(f'{API_URL}/update_teacher', json={
            'name': name,
            'qualification': qualification,
            'phoneNumber': phoneNumber,
            'address': address
        })
        st.write(response.json())

def delete_teacher():
    name = st.text_input('Name')

    if st.button('Delete Teacher'):
        response = requests.delete(f'{API_URL}/delete_teacher', params={'name': name})
        st.write(response.json())

def show_all_teachers():
    if st.button('Show All Teachers'):
        response = requests.get(f'{API_URL}/show_all_teachers')
        st.write(response.json())

def main():
    st.title('University Management System')

    option = st.sidebar.selectbox('Select Operation', [
        'Manage Students',
        'Manage Teachers'
    ])

    if option == 'Manage Students':
        student_option = st.sidebar.selectbox('Student Operations', [
            'Add Student',
            'Search Student',
            'Update Student',
            'Delete Student',
            'Show All Students'
        ])
        if student_option == 'Add Student':
            add_student()
        elif student_option == 'Search Student':
            search_student()
        elif student_option == 'Update Student':
            update_student()
        elif student_option == 'Delete Student':
            delete_student()
        elif student_option == 'Show All Students':
            show_all_students()
    
    elif option == 'Manage Teachers':
        teacher_option = st.sidebar.selectbox('Teacher Operations', [
            'Add Teacher',
            'Update Teacher',
            'Delete Teacher',
            'Show All Teachers'
        ])
        if teacher_option == 'Add Teacher':
            add_teacher()
        elif teacher_option == 'Update Teacher':
            update_teacher()
        elif teacher_option == 'Delete Teacher':
            delete_teacher()
        elif teacher_option == 'Show All Teachers':
            show_all_teachers()

if __name__ == '__main__':
    main()
