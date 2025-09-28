

using System;
using System.Collections.Generic;

namespace EmployeeManagement.Modules
{
    public class EmployeeManager
    {
        private List<Employee> employees = new List<Employee>();

        public void AddEmployee(Employee employee)
        {
            employees.Add(employee);
            Console.WriteLine("Employee added successfully!");
        }

        public void ListEmployees()
        {
            if (employees.Count == 0)
            {
                Console.WriteLine("No employees to display.");
                return;
            }

            foreach (var emp in employees)
            {
                emp.DisplayInfo();
            }
        }

        public void RemoveEmployee(int id)
        {
            Employee emp = employees.Find(e => e.Id == id);
            if (emp != null)
            {
                employees.Remove(emp);
                Console.WriteLine("Employee removed successfully.");
            }
            else
            {
                Console.WriteLine("Employee not found.");
            }
        }
    }
}

