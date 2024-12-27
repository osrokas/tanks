# To setup the project, you need to install guidelines. You can install it by running the following commands:

## 1. Run the following commands in the terminal:
```
python setup.py install
```

## 2. Under build\lib.win-amd64-cpython-312 path copy SDL2.dll and SDL2_image.dll files.

## 3. Run install second time:
```
python setup.py build_ext --inplace
```

## 4. To clean the project, run the following command:
```
python setup.py clean --all
```

# To run the project, for test run the following command:

```
python test.py
```