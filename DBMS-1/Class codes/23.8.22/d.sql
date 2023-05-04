declare
vr_employee employees%rowtype;

begin
select *
into vr_employee
from employees
where employee_id=156;
dbms_output.put_line(vr_employee.first_name|| vr_employee.last_name|| ' has an ID of 156');


end;
/