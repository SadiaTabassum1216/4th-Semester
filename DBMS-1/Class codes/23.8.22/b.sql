 declare
   v_counter number:=10;
   begin
while v_counter>0
   loop
   dbms_output.put_line('v_counter= '||v_counter);
	v_counter:=v_counter-1;
    end loop;

   
   end;
/
 