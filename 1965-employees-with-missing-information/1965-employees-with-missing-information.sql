# Write your MySQL query statement below

SELECT employee_id from Employees where employee_id NOT IN(select employee_id from Salaries)
UNION
select employee_id from Salaries where employee_id NOT IN(SELECT employee_id from Employees)
order by employee_id asc;
