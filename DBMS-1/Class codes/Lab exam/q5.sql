(select distinct sailors.sname
from sailors,reserve,boats
where boats.bid=reserve.bid and reserve.sid=sailors.sid and color='red')

intersect

(select distinct sailors.sname
from sailors,reserve,boats
where boats.bid=reserve.bid and reserve.sid=sailors.sid and color='green');