declare 
v_phone varchar2(15);
begin
v_phone := '8006330575';
format_phone(v_phone);
DBMS_OUTPUT.PUT_LINE(v_phone);
END;
/