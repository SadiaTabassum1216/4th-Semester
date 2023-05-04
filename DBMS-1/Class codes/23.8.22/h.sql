drop table new;
create table new(first_name varchar(20),last_name varchar(20), salary number);
declare
cursor c_zip IS
select *
from employees
where salary>5000;
vr_zip c_zip%rowtype;



begin
open c_zip;
loop
fetch c_zip into vr_zip;
exit when c_zip%NOTFOUND;
insert into new values(vr_zip.first_name,vr_zip.last_name,vr_zip.salary);
select * from new;
end loop;
end;
/