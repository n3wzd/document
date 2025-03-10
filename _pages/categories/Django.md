---
title: "Django"
layout: archive
permalink: categories/django
author_profile: true
---

{% assign posts = site.categories.Django %}
{% for post in posts %} {% include archive-single.html %} {% endfor %}
