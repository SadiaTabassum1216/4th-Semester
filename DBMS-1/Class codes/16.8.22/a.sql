CREATE OR REPLACE FUNCTION get_sal(p_id employees.employee_id%type) 
RETURN NUMBER IS 
v_sal employees.salary%type :=0;

BEGIN
SELECT salary INTO v_sal
FROM employees
WHERE employee_id=p_id;
RETURN v_sal;

END get_sal;
/