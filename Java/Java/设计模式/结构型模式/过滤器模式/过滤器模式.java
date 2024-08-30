package 设计模式.结构型模式.过滤器模式;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

enum Gender {
    MALE, FEMALE
}

enum MaritalStatus {
    SINGLE, MARRIED
}

interface Criteria {
    List<Person> meet(List<Person> people);
}

class Person {
    private String name;
    private int age;
    private Gender gender;
    private MaritalStatus maritalStatus;

    Person(String name, int age, Gender gender, MaritalStatus maritalStatus) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.maritalStatus = maritalStatus;
    }

    public int getAge() {
        return age;
    }

    public Gender getGender() {
        return gender;
    }

    public MaritalStatus getMaritalStatus() {
        return maritalStatus;
    }

    public String getName() {
        return name;
    }

    public void show() {
        System.out.println(name + " " + age + " " + gender + " " + maritalStatus);
    }
}

class MaleCriteria implements Criteria {
    @Override
    public List<Person> meet(List<Person> people) {
        return people.stream()
                .filter(person -> person.getGender() == Gender.MALE)
                .collect(Collectors.toList());
    }
}

class SingleCriteria implements Criteria {
    @Override
    public List<Person> meet(List<Person> people) {
        return people.stream()
                .filter(person -> person.getMaritalStatus() == MaritalStatus.SINGLE)
                .collect(Collectors.toList());
    }
}

class AndCriteria implements Criteria {
    Criteria criteria1;
    Criteria criteria2;

    public AndCriteria(Criteria criteria1, Criteria criteria2) {
        this.criteria1 = criteria1;
        this.criteria2 = criteria2;
    }

    @Override
    public List<Person> meet(List<Person> people) {
        List<Person> result = criteria1.meet(people);
        result = criteria2.meet(result);
        return result;
    }
}

class OrCriteria implements Criteria {
    Criteria criteria1;
    Criteria criteria2;

    public OrCriteria(Criteria criteria1, Criteria criteria2) {
        this.criteria1 = criteria1;
        this.criteria2 = criteria2;
    }

    @Override
    public List<Person> meet(List<Person> people) {
        List<Person> result1 = criteria1.meet(people);
        List<Person> result2 = criteria2.meet(people);
        for(Person person : result1) {
            if(!result2.contains(person)) {
                result2.add(person);
            }
        }
        return result2;
    }
}

public class 过滤器模式 {
    private static void showPeople(List<Person> people) {
        for (Person person : people) {
            person.show();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Person p1 = new Person("aaa", 20, Gender.MALE, MaritalStatus.SINGLE);
        Person p2 = new Person("bbb", 20, Gender.FEMALE, MaritalStatus.SINGLE);
        Person p3 = new Person("ccc", 20, Gender.FEMALE, MaritalStatus.MARRIED);
        Person p4 = new Person("ddd", 20, Gender.MALE, MaritalStatus.MARRIED);
        Criteria maleCriteria = new MaleCriteria();
        Criteria singleCriteria = new SingleCriteria();
        Criteria andCriteria = new AndCriteria(maleCriteria, singleCriteria);
        Criteria orCriteria = new OrCriteria(maleCriteria, singleCriteria);
        List<Person> people = new ArrayList<Person>(){{
            add(p1);
            add(p2);
            add(p3);
            add(p4);
        }};
        showPeople(maleCriteria.meet(people));
        showPeople(singleCriteria.meet(people));
        showPeople(andCriteria.meet(people));
        showPeople(orCriteria.meet(people));
    }
}
