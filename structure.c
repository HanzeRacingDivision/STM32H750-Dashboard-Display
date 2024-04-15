void SensorRead()
{
  temp = digitalRead(tempSens);
  other = digitalRead(randomSens);
}


int updateValues()
{
  gauge1.updateValue(sensorRead.temp, delayTime);
  return gauge1.getValue;
}

void handleFires()
{

  if updateValues() >= threshold //Temperature too high or something
  {
    temp.warning = true;
  }

}


int main(){

  SensorRead();

  while(1)
  {
  updateValues();
  handleFires();
  }
  
}
