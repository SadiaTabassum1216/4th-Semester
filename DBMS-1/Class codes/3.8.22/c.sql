declare 
v_phone varchar2(30);
begin
select phone into v_phone
from table1 where id=1;
formatting(v_phone);
insert into table2 values(1,v_phone);
DBMS_OUTPUT.PUT_LINE(v_phone);
END;
/