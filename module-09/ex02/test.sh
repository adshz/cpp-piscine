#!/bin/bash
# Test script for PmergeMe (ex02)
# Usage: bash test.sh

PROG="./PmergeMe"
PASS=0
FAIL=0
TOTAL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

run_test() {
	local desc="$1"
	shift
	local expect_error="$1"
	shift
	TOTAL=$((TOTAL + 1))
	local output
	output=$($PROG "$@" 2>&1)
	local exit_code=$?

	if [ "$expect_error" = "error" ]; then
		if [ $exit_code -ne 0 ]; then
			echo -e "  ${GREEN}[PASS]${NC} $desc"
			PASS=$((PASS + 1))
		else
			echo -e "  ${RED}[FAIL]${NC} $desc (expected error, got exit 0)"
			FAIL=$((FAIL + 1))
		fi
		return
	fi

	# Check exit code
	if [ $exit_code -ne 0 ]; then
		echo -e "  ${RED}[FAIL]${NC} $desc (non-zero exit: $exit_code)"
		FAIL=$((FAIL + 1))
		return
	fi

	# Extract the "After:" line and verify it's sorted
	local after_line
	after_line=$(echo "$output" | grep "^After:")
	if [ -z "$after_line" ]; then
		echo -e "  ${RED}[FAIL]${NC} $desc (no 'After:' line in output)"
		FAIL=$((FAIL + 1))
		return
	fi

	# Get sorted numbers from After line
	local nums
	nums=$(echo "$after_line" | sed 's/^After://')

	# Check if sorted
	local prev="-1"
	local is_sorted=true
	for n in $nums; do
		if [ "$n" -lt "$prev" ] 2>/dev/null; then
			is_sorted=false
			break
		fi
		prev=$n
	done

	if $is_sorted; then
		echo -e "  ${GREEN}[PASS]${NC} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "  ${RED}[FAIL]${NC} $desc (output not sorted)"
		echo "         After: $nums"
		FAIL=$((FAIL + 1))
	fi
}

# Check count matches
run_count_test() {
	local desc="$1"
	shift
	local input_args=("$@")
	local input_count=${#input_args[@]}
	TOTAL=$((TOTAL + 1))
	local output
	output=$($PROG "${input_args[@]}" 2>&1)
	local after_line
	after_line=$(echo "$output" | grep "^After:" | sed 's/^After://')
	local output_count
	output_count=$(echo $after_line | wc -w)

	if [ "$output_count" -eq "$input_count" ]; then
		echo -e "  ${GREEN}[PASS]${NC} $desc (in=$input_count, out=$output_count)"
		PASS=$((PASS + 1))
	else
		echo -e "  ${RED}[FAIL]${NC} $desc (in=$input_count, out=$output_count)"
		FAIL=$((FAIL + 1))
	fi
}

echo ""
echo "=========================================="
echo "   PmergeMe Test Suite"
echo "=========================================="

# Build
echo ""
echo -e "${YELLOW}Building...${NC}"
make re 2>&1 | tail -1
if [ ! -f "$PROG" ]; then
	echo -e "${RED}Build failed!${NC}"
	exit 1
fi
echo ""

# ---- ERROR CASES ----
echo "--- Error Cases ---"
run_test "No arguments"            error
run_test "Negative number"         error 1 -2 3
run_test "Non-numeric input"       error 1 abc 3
run_test "Float input"             error 1 2.5 3
run_test "Empty string"            error ""
run_test "Special characters"      error "1 @ 3"

# ---- BASIC SORTING ----
echo ""
echo "--- Basic Sorting (5-10 elements) ---"
run_test "5 elements"              ok 5 3 8 1 9
run_test "6 elements"              ok 42 21 7 99 3 15
run_test "7 elements"              ok 5 3 8 1 9 2 7
run_test "8 elements"              ok 8 4 2 6 1 3 7 5
run_test "9 elements"              ok 9 8 7 6 5 4 3 2 1
run_test "10 elements"             ok 10 3 7 1 9 4 8 2 6 5

# ---- EDGE CASES ----
echo ""
echo "--- Edge Cases ---"
run_test "Single element"          ok 42
run_test "Two elements"            ok 2 1
run_test "Two elements sorted"     ok 1 2
run_test "Three elements"          ok 3 1 2
run_test "Already sorted"          ok 1 2 3 4 5
run_test "Reverse sorted"          ok 5 4 3 2 1
run_test "All same values"         ok 7 7 7 7 7
run_test "Duplicates"              ok 5 5 3 3 1 1
run_test "Large value"             ok 2147483647 1 42

# ---- ELEMENT COUNT PRESERVATION ----
echo ""
echo "--- Element Count Preservation ---"
run_count_test "5 elements count"  5 3 8 1 9
run_count_test "7 elements count"  5 3 8 1 9 2 7
run_count_test "Duplicates count"  5 5 3 3 1 1

# ---- MEDIUM SIZE ----
echo ""
echo "--- Medium Size (100 elements) ---"
ARGS_100=$(shuf -i 1-10000 -n 100 | tr "\n" " ")
run_test "100 random elements" ok $ARGS_100

# ---- LARGE SIZE (eval requirement) ----
echo ""
echo "--- Large Size (eval: shuf -i 1-1000 -n 3000) ---"
ARGS_3000=$(shuf -i 1-100000 -n 3000 | tr "\n" " ")
run_test "3000 random elements" ok $ARGS_3000

# ---- TIMING DISPLAY ----
echo ""
echo "--- Timing Output Check ---"
TOTAL=$((TOTAL + 1))
TIMING_OUTPUT=$($PROG 5 3 8 1 9 2 7 2>&1)
HAS_BEFORE=$(echo "$TIMING_OUTPUT" | grep -c "^Before:")
HAS_AFTER=$(echo "$TIMING_OUTPUT" | grep -c "^After:")
HAS_VEC=$(echo "$TIMING_OUTPUT" | grep -c "std::vector")
HAS_DEQ=$(echo "$TIMING_OUTPUT" | grep -c "std::deque")
if [ "$HAS_BEFORE" -eq 1 ] && [ "$HAS_AFTER" -eq 1 ] && [ "$HAS_VEC" -eq 1 ] && [ "$HAS_DEQ" -eq 1 ]; then
	echo -e "  ${GREEN}[PASS]${NC} Output format (Before/After/vector time/deque time)"
	PASS=$((PASS + 1))
else
	echo -e "  ${RED}[FAIL]${NC} Output format missing lines"
	FAIL=$((FAIL + 1))
fi

# ---- SHOW SAMPLE OUTPUT ----
echo ""
echo "--- Sample Output ---"
echo "$TIMING_OUTPUT"

# ---- LARGE RUN TIMING ----
echo ""
echo "--- Large Run (3000 elements) Timing ---"
$PROG $ARGS_3000 2>&1 | tail -2

# ---- SUMMARY ----
echo ""
echo "=========================================="
if [ $FAIL -eq 0 ]; then
	echo -e "  ${GREEN}All $TOTAL tests passed!${NC}"
else
	echo -e "  ${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC} out of $TOTAL"
fi
echo "=========================================="
echo ""
