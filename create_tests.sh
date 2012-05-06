#!/bin/sh
filelist=$@
for file in ${filelist}
do
	function_list=$(egrep '^char \*test_' $file |\
		sed 's/char \*/        /'  |\
		sed 's/(.*)//')
	echo "Test_Data *testing_$(echo $file | sed 's/\.c$//')(void)"
	echo "{"
	echo "    Test_Data *testdata = malloc(sizeof(Test_Data));"
	echo "    MU_RUN_TESTS(event_handler,"
	echo "        testdata,"
	echo ${function_list} | awk '{for (i=1; i<NF; i++) {print "        "$i","}; print "        "$i"};"}'
	echo "    return testdata;"
	echo "}"
done
