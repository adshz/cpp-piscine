# Bitcoin Exchange - Test Files

## Build

```bash
make
```

## Usage

```bash
./btc <input_file>
```

## Test Files

### test_edge_cases.txt
Tests boundary conditions:
- First available date in database (2009-01-02)
- Dates before database exists (2008-01-01)
- Future dates (2025-01-01)
- Leap year dates (2012-02-29, 2000-02-29, 1900-02-29)
- Min/max valid values (0, 1000)

```bash
./btc test_edge_cases.txt
```

### test_values.txt
Tests value validation:
- Negative values (-1, -0.01, -1000)
- Values exceeding 1000 (1001, 1000.01)
- Overflow values (2147483648, 999999999)
- Non-numeric values (abc, 1a, a1)
- Empty value
- Valid boundary values (0, 1000, 0.001)

```bash
./btc test_values.txt
```

### test_wrong_dates.txt
Tests invalid date formats:
- Invalid month (13, 00)
- Invalid day (00, 32)
- Invalid days for month (Feb 29 non-leap, Feb 30, Apr 31)
- Wrong separators (/, .)
- Wrong date order (DD-MM-YYYY)
- Malformed dates (double dash, negative year)

```bash
./btc test_wrong_dates.txt
```

### test_errors.txt
Interleaved valid and invalid entries to test error handling doesn't break subsequent parsing:
- Valid entries mixed with invalid dates/formats
- Missing date, missing value, missing separator

```bash
./btc test_errors.txt
```

### test_empty.txt
Empty file to test handling of empty input.

```bash
./btc test_empty.txt
```

## Run All Tests

```bash
for f in test_*.txt; do echo "=== $f ==="; ./btc "$f"; echo; done
```
