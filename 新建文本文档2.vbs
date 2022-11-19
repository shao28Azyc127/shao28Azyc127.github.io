dim a
a=inputbox("what sentense?")
do
createobject("SAPI.SpVoice").Speak a
wscript.sleep(200)
loop