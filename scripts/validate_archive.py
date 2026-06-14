#!/usr/bin/env python3
"""Fail when new tracked local/cache/build artifacts enter the archive."""

from __future__ import annotations

import fnmatch
import subprocess  # nosec B404 - fixed local git invocation for tracked file listing.
import sys
from pathlib import PurePosixPath


DENY_PATTERNS = (
    ".DS_Store",
    "._*",
    "__pycache__/*",
    "*.pyc",
    "*.pyo",
    ".pytest_cache/*",
    ".mypy_cache/*",
    ".ruff_cache/*",
    ".coverage",
    ".coverage.*",
    "htmlcov/*",
    ".env",
    ".env.*",
    ".venv/*",
    "venv/*",
    "env/*",
    "ENV/*",
    "*.o",
    "*.gcda",
    "*.gcno",
    "*.gcov",
    "*.log",
    "*.bak",
    "node_modules/*",
)

ALLOWLIST = {
    "S21/Calculator (on C:C++)/src/test/s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/s21_polish.o",
    "S21/Calculator (on C:C++)/src/test/s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/s21_smart_calc.o",
    "S21/Calculator (on C:C++)/src/test/s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/s21_stack_functions.o",
    "S21/Calculator (on C:C++)/src/test/s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/s21_valid_normal.o",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_stack_functions.gcda",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_valid_normal.gcda",
    "S21/Calculator (on C:C++)/src/test/test_remove_space-s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/test_remove_space.gcda",
    "S21/Calculator (on C:C++)/src/test/test_remove_space.gcno",
    "S21/Calculator (on C:C++)/src/test/test_remove_space.o",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_stack_functions.gcda",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_valid_normal.gcda",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc-s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_smart_calc.o",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_stack_functions.gcda",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_valid_normal.gcda",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish-s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_stack_and_polish.o",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_stack_functions.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_valid_normal.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x-s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_to_lower_and_x.o",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_polish.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_polish.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_smart_calc.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_smart_calc.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_stack_functions.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_stack_functions.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_valid_normal.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_validation-s21_valid_normal.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_validation.gcda",
    "S21/Calculator (on C:C++)/src/test/test_str_validation.gcno",
    "S21/Calculator (on C:C++)/src/test/test_str_validation.o",
    "S21/DevOps/8/src/services/.env",
    "docker_work/flask/__pycache__/app_test.cpython-310.pyc",
    "schpool21/bash/door_management_files/door_logs/door_1.log",
    "schpool21/bash/door_management_files/door_logs/door_10.log",
    "schpool21/bash/door_management_files/door_logs/door_11.log",
    "schpool21/bash/door_management_files/door_logs/door_12.log",
    "schpool21/bash/door_management_files/door_logs/door_13.log",
    "schpool21/bash/door_management_files/door_logs/door_14.log",
    "schpool21/bash/door_management_files/door_logs/door_15.log",
    "schpool21/bash/door_management_files/door_logs/door_16.log",
    "schpool21/bash/door_management_files/door_logs/door_2.log",
    "schpool21/bash/door_management_files/door_logs/door_3.log",
    "schpool21/bash/door_management_files/door_logs/door_4.log",
    "schpool21/bash/door_management_files/door_logs/door_5.log",
    "schpool21/bash/door_management_files/door_logs/door_6.log",
    "schpool21/bash/door_management_files/door_logs/door_7.log",
    "schpool21/bash/door_management_files/door_logs/door_8.log",
    "schpool21/bash/door_management_files/door_logs/door_9.log",
    "schpool21/testing/.DS_Store",
    "schpool21/testing/._cashe.sh",
    "schpool21/vim_and_gitlab/files.log",
    "schpool21/vim_and_gitlab/history_of_vim.txt.bak",
}

ALLOWLIST_SUFFIXES = (
    "/Telegram-bot/__pycache__/config.cpython-310.pyc",
)


def git_ls_files() -> list[str]:
    result = subprocess.run(  # nosec B603 - arguments are static and shell is not used.
        ["git", "ls-files"],
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    return result.stdout.splitlines()


def matches_deny_pattern(path: str) -> bool:
    name = PurePosixPath(path).name
    return any(
        fnmatch.fnmatch(path, pattern) or fnmatch.fnmatch(name, pattern)
        for pattern in DENY_PATTERNS
    )


def is_allowlisted(path: str) -> bool:
    if PurePosixPath(path).name in {".env.example", ".env.sample"}:
        return True
    return path in ALLOWLIST or any(
        path.endswith(suffix) for suffix in ALLOWLIST_SUFFIXES
    )


def main() -> int:
    violations = sorted(
        path
        for path in git_ls_files()
        if matches_deny_pattern(path) and not is_allowlisted(path)
    )

    if violations:
        print("Tracked archive hygiene violations found:")
        for path in violations:
            print(f"  - {path}")
        print(
            "\nRemove these from tracking or add a narrow allowlist entry "
            "if they are intentional archive material."
        )
        return 1

    print("Archive hygiene check passed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
