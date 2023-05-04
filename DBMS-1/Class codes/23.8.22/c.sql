
   begin
	for v_counter in 1..10
   loop
   dbms_output.put_line('v_counter= '||v_counter);	
    end loop;

   for v_counter in reverse 1..10
   loop
   dbms_output.put_line('v_counter= '||v_counter);	
    end loop;
   end;
/