select distinct sailors.sname
from sailors,reserve,boats
where boats.bid=reserve.bid and reserve.sid=sailors.sid and sailor.age>20 and sailors.sname not in

(select distinct sailors.sname
from sailors,reserve,boats
where boats.bid=reserve.bid and reserve.sid=sailors.sid and color='red');

