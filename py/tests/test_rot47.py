from unittest import TestCase


class TestRot47(TestCase):
    def test_rot47_encoding(self):
        from rot47 import rot47
        self.assertNotEqual('a', rot47('a'))
        self.assertEqual('a', rot47(rot47('a')))
        self.assertEqual(' ', rot47(' '))
        self.assertEqual(' ', rot47(rot47(' ')))
