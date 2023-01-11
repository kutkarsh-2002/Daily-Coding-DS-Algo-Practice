# Write your MySQL query statement below

select ifnull(max(salary), null) as SecondHighestSalary from Employee
where salary not in (select max(salary) from Employee);