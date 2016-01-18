void memcpy (void* dst, void* src, byte len)
{
  for(byte i = 0; i<len; ++i)
  {
    *((byte*)(dst+i)) = *((byte*)(src+i));
  }  
}
