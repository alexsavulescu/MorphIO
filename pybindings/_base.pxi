# -*- coding: utf-8 -*-
# =====================================================================================================================
# These bindings were automatically generated by cyWrap. Please do dot modify.
# Additional functionality shall be implemented in sub-classes.
#
__copyright__ = "Copyright 2017 EPFL BBP-project"
# =====================================================================================================================
cimport std
from cython.operator cimport dereference as deref
from libcpp cimport bool
from libc.string cimport memcpy


# -------------------------------------------------------------
# BASE Class
# -------------------------------------------------------------
cdef enum OPERATOR:
    LESS = 0, LESS_EQUAL, EQUAL, DIFF, GREATER, GREATER_EQUAL


cdef class _py__base:
    cdef void *_ptr
    # Basic comparison is done by comparing the inner obj ptr
    def __richcmp__(_py__base self, _py__base other, operation):
        if operation == OPERATOR.EQUAL:
            return self._ptr == other._ptr


# -------------------------------------------------------------
# BASE Array Type
# -------------------------------------------------------------
cdef class _ArrayT(_py__base):
    #Numpy array object
    cdef readonly object nparray

    # Pass on the array API
    def __len__(self):
        return len(self.nparray)

    def __getitem__(self, item):
        return self.nparray.__getitem__(item)

    # Pass on the iterator API
    def __iter__(self):
        return iter(self.nparray)

    # Get a nice representation
    def __repr__(self):
        leng = min(3, len(self.nparray))
        return ("<%s object\n"
                "%s...\n"
                " (Full numpy array accessible at .nparray) >" % (str(type(self)), str(self.nparray[:leng])))


# --------------------------------------------------------
# BASE Enum
# --------------------------------------------------------
cdef class _Enum:
    def __cinit__(self):
        raise TypeError("Cant instantiate Enum")

    @classmethod
    def get_name(cls):
        return cls.__name__

    @classmethod
    def get_description(cls, int item):
        for name, value in cls.__dict__.items():
            if not name.startswith("_") and value == item:
                return name
        raise IndexError("No such Enumerator index")


# --------------------------------------------------------
cdef class _EnumItem:
    cdef object enumcls
    cdef int ord

    def __init__(self, object enumcls, int numeric):
        self.enumcls = enumcls
        self.ord = numeric

    def __int__(self):
        return self.ord

    def __repr__(self):
        return "<ENUM %s.%s: %d>" % (self.enumcls.get_name(), self.enumcls.get_description(self.ord), self.ord)

    def __str__(self):
        return "%s.%s (%d)" % (self.enumcls.get_name(), self.enumcls.get_description(self.ord), self.ord)

    @property
    def name(self):
        return self.enumcls.get_description(self.ord)

    def __richcmp__(_EnumItem self, other, operation):
        if operation == OPERATOR.EQUAL:
            return isinstance(other, (int, self.enumcls)) and int(self) == int(other)
        raise TypeError("Operation not supported by enums")