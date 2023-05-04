create or replace procedure raise_salary
(p_id in employees.employee_id%type, p_percent in number)

IS
BEGIN
UPDATE employees
SET salary=salary*(1+p_percent/100)
WHERE employee_id=p_id;
END raise_salary;
/