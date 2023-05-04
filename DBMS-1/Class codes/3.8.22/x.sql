create or replace procedure format_phone
(p_phone_no in out varchar2)
is
begin
p_phone_no := '(' || SUBSTR(p_phone_no,1,3) ||') ' || SUBSTR(p_phone_no,4,3) ||'-' || SUBSTR(p_phone_no,7);
END format_phone;
/