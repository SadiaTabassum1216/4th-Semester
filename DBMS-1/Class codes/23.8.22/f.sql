declare
cursor c_zip IS
select *
from employees;
vr_zip c_zip%rowtype;

begin
open c_zip;
loop
fetch c_zip into vr_zip;
exit when c_zip%NOTFOUND;

dbms_output.put_line(vr_zip.employee_id);
end loop;
end;
/