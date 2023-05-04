CREATE OR REPLACE FUNCTION get_tax
(p_id employees.employee_id%type) RETURN NUMBER IS v_tax employees.salary%type :=0;

BEGIN
SELECT salary*12*0.1
INTO v_tax
FROM employees
WHERE employee_id=p_id;
RETURN v_tax;

END get_tax;
/