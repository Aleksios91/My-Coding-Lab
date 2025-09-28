using System;
using EmployeeManagement.Modules;

class Program
{
    static void Main()
    {
        EmployeeManager manager = new EmployeeManager();

        char choice;
        do
        {
            Console.WriteLine("\n--- Employee Management System ---");
            Console.WriteLine("A. Add Employee");
            Console.WriteLine("B. List Employees");
            Console.WriteLine("C. Remove Employee");
            Console.WriteLine("E. Exit");
            Console.Write("Choose an option: ");
            string input = Console.ReadLine();
            choice = char.ToUpper(input[0]);
            Console.WriteLine();

            switch (choice)
            {
                case 'A':
                    Console.Write("Enter ID: ");
                    int id = int.Parse(Console.ReadLine());

                    Console.Write("Enter Name: ");
                    string name = Console.ReadLine();

                    Console.Write("Enter Position: ");
                    string position = Console.ReadLine();

                    Console.Write("Enter Salary: ");
                    decimal salary = decimal.Parse(Console.ReadLine());

                    Employee newEmployee = new Employee(id, name, position, salary);
                    manager.AddEmployee(newEmployee);
                    break;

                case 'B':
                    manager.ListEmployees();
                    break;

                case 'C':
                    Console.Write("Enter ID to remove: ");
                    int removeId = int.Parse(Console.ReadLine());
                    manager.RemoveEmployee(removeId);
                    break;

                case 'E':
                    Console.WriteLine("Goodbye!");
                    break;

                default:
                    Console.WriteLine("Invalid choice! Try again.");
                    break;
            }
        } while (choice != 'E');
    }
}

