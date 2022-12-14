select distinct(city)
from station
where city not regexp('[aeiou]$') and city not regexp('^[aeiou]');