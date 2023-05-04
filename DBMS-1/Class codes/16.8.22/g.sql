declare
num1 number:=4;
num2 number:=2;
num3 number:=9;
temp number;
begin
if num1>num2 and num1>num3
	then temp:=num1;
	end if;
if num2>num1 and num2>num3
	then temp:=num2;
	end if;
if num3>num1 and num3>num2
	then temp:=num3;
	end if;
dbms_output.put_line(temp);
end;
/
