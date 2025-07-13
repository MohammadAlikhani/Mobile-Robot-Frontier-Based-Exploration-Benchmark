from setuptools import find_packages
from setuptools import setup

setup(
    name='upc_mrn',
    version='0.0.0',
    packages=find_packages(
        include=('upc_mrn', 'upc_mrn.*')),
)
