#!/bin/bash
set -euo pipefail

# Go to script dir
script_dir="$(dirname $BASH_SOURCE)"
echo "Script dir: $script_dir"
cd "$script_dir"

# Find python
if command -v python3 >/dev/null 2>&1; then
	PY_CMD="python3"
elif command -v python >/dev/null 2>&1; then
	PY_CMD="python"
else
	PY_CMD=""
fi

if [ -n "$PY_CMD" ]; then
	echo "Python command: $PY_CMD ($( $PY_CMD --version 2>&1 ))"
else
	echo "Python not found"
fi

# Find pip
if command -v pip3 >/dev/null 2>&1; then
	PIP_CMD="pip3"
elif command -v pip >/dev/null 2>&1; then
	PIP_CMD="pip"
else
	PIP_CMD=""
fi

if [ -n "$PIP_CMD" ]; then
	echo "Pip command: $PIP_CMD ($( $PIP_CMD --version 2>&1 ))"
else
	echo "Pip not found"
fi

# Optional: exit non-zero if required tools missing
if [[ -z "$PY_CMD" || -z "$PIP_CMD" ]]; then
	echo "One or more required commands are missing." >&2
	exit 1
fi

# Check .env/
if [ -d ".env/" ]; then
	echo ".env exists"
else
	echo ".env NOT found"
	echo "create python environment ..."
	python -m venv .env
	echo "done."
fi

# Activate env
echo "Sourcing env ..."
source .env/bin/activate

# Installing requierments
echo "Installing requierments ..."
pip install -r requirements.txt

echo "READY! Building website"

# Mkdocs build & serve
mkdocs build 
mkdocs serve
