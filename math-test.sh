#!/bin/sh

for TESTFILE in `ls -1 tests/*.t`; do
	BAD_TEST=0
	echo -n "Running test $TESTFILE: "
	TESTSTRING=`sed -n 1p $TESTFILE`
	TESTRESULT=`sed -n 2p $TESTFILE`

  ( [ -z "$TESTSTRING" ] || [ -z "$TESTRESULT" ] ) && BAD_TEST=1
	if [ $BAD_TEST -gt 0 ]; then
		echo "test is misformatted"
		exit 1
	fi

	BC_TESTRESULT=`echo "$TESTSTRING" | bc`
	RDP_TESTRESULT=`echo "$TESTSTRING" | ./rdp`

	if [ $BC_TESTRESULT -eq $TESTRESULT ]; then
		echo -n ""
		else
		echo "(the test did not evalulate correctly with bc)"
		exit 1
		fi
	if [ $RDP_TESTRESULT -eq $BC_TESTRESULT ]; then
		echo "PASS"
	  else
		echo "FAIL"
		echo "test:     $TESTSTRING"
		echo "result:   $RDP_TESTRESULT"
		echo "expected: $TESTRESULT"
		echo "(the test failed: result was $RDP_TESTRESULT - should heave been $BC_TESTRESULT)"
		exit 1
		fi
	done	
