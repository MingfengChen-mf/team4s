from setuptools import find_packages
from setuptools import setup

setup(
    name='team4s_interfaces',
    version='0.2.0',
    packages=find_packages(
        include=('team4s_interfaces', 'team4s_interfaces.*')),
)
