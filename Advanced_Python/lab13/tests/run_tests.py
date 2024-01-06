import unittest

loader = unittest.TestLoader()
suite = loader.discover('tests')  # Assumes your tests are in the 'tests' directory
runner = unittest.TextTestRunner()
runner.run(suite)