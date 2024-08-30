package 设计模式.结构型模式.组合模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

class Employee {
    private String name;
    private String position;
    private List<Employee> subordinates = new ArrayList<>();

    public Employee(String name, String position) {
        this.name = name;
        this.position = position;
    }

    public void add(Employee employee) {
        subordinates.add(employee);
    }

    public void remove(Employee employee) {
        subordinates.remove(employee);
    }

    public void show(){
        System.out.println(this.name + " : " + this.position);
    }

    public List<Employee> getSubordinates() {
        return subordinates;
    }
}

public class 组合模式 {
    static void showAll(Employee e){
        e.show();
        List<Employee> subordinates = e.getSubordinates();
        if (subordinates != null) {
            for (Employee sub : subordinates) {
                showAll(sub);
            }
        }
    }

    public static void main(String[] args) {
        Employee e1 = new Employee("Tom", "CEO");
        Employee e2 = new Employee("Jack", "Head Sales");
        Employee e3 = new Employee("Mike", "Head Development");
        Employee e4 = new Employee("Able", "Sales");
        Employee e5 = new Employee("Bin", "Sales");
        Employee e6 = new Employee("Elk", "Development");
        Employee e7 = new Employee("Knight", "Development");
        e1.add(e2);
        e1.add(e3);
        e2.add(e4);
        e2.add(e5);
        e3.add(e6);
        e3.add(e7);
        showAll(e1);
    }
}
