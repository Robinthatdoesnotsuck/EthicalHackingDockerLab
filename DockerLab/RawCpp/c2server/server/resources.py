import uuid
import json

from flask import request, Response
from flask_restful import Resource
from database.db import intialize_db
from database.models import Task


class Tasks(Resource):
    def get(self):
        return "GET success!", 200

    def post(self):
        return "POST success!", 200


class Results(Resource):
    def get(self):
        return "GET success!", 200

    def post(self):
        return "POST success!", 200


class History(Resource):
    def get(self):
        return "GET success!", 200
