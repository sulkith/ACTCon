void ForceFeedback_ini()
{
  pinMode(FFPin, OUTPUT);
  digitalWrite(FFPin, HIGH);
}
void ForceFeedback_cyclic()
{
  #ifdef FORCE_FEEDBACK
    if(percentage > 50)
    {
      digitalWrite(FFPin, LOW);
    }
    else
    {
      digitalWrite(FFPin, HIGH);  
    }
  #else
    digitalWrite(FFPin, HIGH);
  #endif
}
