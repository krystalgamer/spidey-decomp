ok=$(grep -R "@Ok" *.cpp | wc -l)
notok=$(grep -R "@NotOk" *.cpp | wc -l)
btodo=$(grep -R "@BIGTODO" *.cpp | wc -l)
mtodo=$(grep -R "@MEDIUMTODO" *.cpp | wc -l)
stodo=$(grep -R "@SMALLTODO" *.cpp | wc -l)

echo "@Ok $ok"
echo "@NotOk $notok"
echo "@BIGTODO $btodo"
echo "@MEDIUMTODO $mtodo"
echo "@SMALLTODO $stodo"
