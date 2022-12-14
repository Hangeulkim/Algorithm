select distinct(city)
from station
where city not regexp('[aeiou]$') or city not regexp('^[aeiou]');