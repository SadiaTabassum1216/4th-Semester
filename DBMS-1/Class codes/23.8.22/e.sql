declare
vr_employee employees%rowtype;

begin
select *
into vr_employee
from employees
where employee_id=&x;

dbms_output.put_line(vr_employee.first_name||' '|| vr_employee.last_name|| '''s tax is ' ||(vr_employee.SALARY+vr_employee.SALARY*NVL(vr_employee.COMMISSION_PCT,0))*12*0.1);


end;
/