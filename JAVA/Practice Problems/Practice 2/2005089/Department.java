import java.lang.String;

public class Department {

    private int id;
    private String name;
    private Employee[] employees;
    private int employeeCount;
    // add your code here
    static private int dept_number;
    static public Department[] departments= new Department[10];
    // you are allowed to add variables here
    // there can be at most 10 departments

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];
        // add your code here
        departments[dept_number++]=this;
    }

    // add your code here
    public void addEmployee(Employee e) {
        if (employeeCount == 10) {
            System.out.println("Max number of employees are equipped.");

        }

        employees[employeeCount] = e;
        employeeCount++;
    }

    public double getDepartmentSalary()
    {
        double sum=0;
        for(int i=0;i<employeeCount;i++)
            sum+=employees[i].getSalary();
        return sum;
    }

    public Employee getMaxSalaryEmployee()
    {
        Employee max=employees[0];

        for(int i=0;i<employeeCount;i++)
        {
            if(employees[i].getSalary() > max.getSalary())
                max=employees[i];
        }

        return max;
    }

    static public double getTotalSalary() {
        double sum=0;

        for(int i=0; i<dept_number; i++)
            sum=sum+departments[i].getDepartmentSalary();

        return sum;
    }


    void giveIncrementToEmployees(double inc)
    {
        for(int i=0; i<employeeCount; i++ )
        {
            employees[i].setSalary(employees[i].getSalary()+inc);
        }
    }




}