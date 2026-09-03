#!/usr/bin/env python3
"""Run the supplied sample input/output fixtures against the executable."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: run_samples.py PATH_TO_EX1", file=sys.stderr)
        return 2

    executable = Path(sys.argv[1]).resolve()
    fixtures = Path(__file__).resolve().parent / "fixtures"
    failures: list[int] = []

    for index in range(1, 7):
        test_input = (fixtures / f"test{index}.in").read_text(encoding="utf-8")
        expected = (fixtures / f"expected{index}.out").read_text(encoding="utf-8")
        result = subprocess.run(
            [str(executable)],
            input=test_input,
            text=True,
            capture_output=True,
            check=False,
        )
        if result.returncode != 0 or result.stdout != expected:
            failures.append(index)
            print(f"sample {index} failed", file=sys.stderr)
            if result.stderr:
                print(result.stderr, file=sys.stderr)

    if failures:
        print(f"failing samples: {failures}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
